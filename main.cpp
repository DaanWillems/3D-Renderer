#ifdef main
#undef main
#endif /* main */

#include <iostream>
#include <list>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <ui/sdl/window.h>
#include <ui/renderer.h>
#include <math/vec4.h>
#include <math/grid.h>
#include <math/mat4.h>
#include <math/mesh.h>

#include <stdio.h>
#include <fcntl.h>
#include <game/input_manager.h>
#include <ui/mesh_loader.h>
#include <game/cube.h>
#include <game/spaceship.h>
#include <game/planet.h>
#include <game/asteroid.h>
#include <chrono>
#include <ctime>

#ifdef _WIN32

#include <io.h>
#include <windows.h>
#include <cmath>
#include <game/planet.h>
#include <algorithm>

#endif
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

using namespace ui;
using namespace math;
using namespace ui::sdl;

int main(int argc, char *argv[]) {
    ui::sdl::window window{};
    window.init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 10, 10);

    renderer renderer{window};
    scene scene{};

    game::spaceship spaceship{};
    game::planet planet{};
    planet.location({0.f, 0.f, -70.f});

    scene.renderables.push_back(&spaceship);
    scene.renderables.push_back(&planet);

    std::array<game::asteroid, 8> asteroids{};
    for (int i = 0; i < asteroids.size(); ++i) {
        auto &asteroid = asteroids[i];
        asteroid.location({-50.f + (i % 5) * 100.f, -10.f + (i % 3) * 10, i * 40.f});
        scene.renderables.push_back(&asteroid);
    }

    scene.renderables.push_back(&spaceship);
    scene.renderables.push_back(&planet);

    float near_plane{0.1f};
    float far_plane{500.f};
    float alpha{1.5f};

    game::input_manager input;

    math::vec4 eye{0, 60, 60};
    math::vec4 lookat{0, 0, 0};
    math::mat4 projection{1};

    float scale = 1 / (tan((alpha / 2) * (static_cast<float>( M_PI ) / 180)));

    projection.data[0][0] = scale;
    projection.data[1][1] = scale;
    projection.data[2][2] = -far_plane / (far_plane - near_plane);
    projection.data[3][2] = -far_plane * near_plane / (far_plane - near_plane);

    projection.data[3][3] = 0.f;
    projection.data[2][3] = -1.f;

    renderer.projection(projection);
    std::list<game::projectile> projectiles{};
    bool can_shoot{true};
    bool can_toggle_decouple{true};

    auto start_time = std::chrono::system_clock::now();
    auto last_time = std::chrono::system_clock::now();

    spaceship.scale({150.f, 150.f, 150.f});
    int p_id = 0;
    vec4 cam_target_offset{0.f, 0.f, 0.f};

    float cam_rotation_angle{0.f};
    float i{};

    while (!window.shouldClose()) {
        start_time = std::chrono::system_clock::now();
        auto delta_time =
                std::chrono::duration_cast<std::chrono::microseconds>(start_time - last_time).count() / 100000.f;
        last_time = start_time;

        spaceship.update(delta_time);
        planet.update(delta_time);

        spaceship.acceleration(vec4{0.f, 0.f, 0.f});

        for (auto &asteroid : asteroids) {
            if (asteroid.check_collision(spaceship)) {
                std::cout << "Je hebt verloren!\n";
            }
            asteroid.update(delta_time);
        }
        if (planet.check_collision(spaceship)) {
            std::cout << "Je hebt verloren!\n";
        }

        math::vec4 spaceship_direction{0.f, 0.f, 1.f};
        math::mat4 rotate_{1.f};
        rotate_.rotate_axis(spaceship.roll(), {0.f, 0.f, 1.f});
        rotate_.rotate_axis(spaceship.yaw(), {0.f, 1.f, 0.f});
        rotate_.rotate_axis(spaceship.pitch(), {1.f, 0.f, 0.f});

        spaceship_direction = math::invert(spaceship_direction.multiply(rotate_));
        math::mat4 test{1.f};
        test.rotate_axis(90, {1, 0, 0});

        auto spaceship_up = math::normalize(spaceship_direction.multiply(test));

        lookat = spaceship.location();
        lookat += cam_target_offset;
        eye = spaceship.location() - spaceship_direction * 90;
        eye += cam_target_offset;
        eye.y(eye.y() + 50);

        mat4 r{1.f};
        r.translate(eye);
        r.rotate(spaceship.rotation().z(), {0.f, 0.f, 1.f});
        r.rotate(spaceship.rotation().y(), {0.f, 1.f, 0.f});
        r.rotate(spaceship.rotation().x(), {1.f, 0.f, 0.f});

        float camera_speed{1.f};
        float turn_speed{10.f};
        float acceleration{3.f};

        if (input.is_key_pressed(game::key::PAGEUP)) {
            cam_target_offset.data[1] -= camera_speed;
        }
        if (input.is_key_pressed(game::key::PAGEDOWN)) {
            cam_target_offset.data[1] += camera_speed;
        }
        if (input.is_key_pressed(game::key::LEFT)) {
            cam_target_offset.data[0] -= camera_speed;
        }
        if (input.is_key_pressed(game::key::RIGHT)) {
            cam_target_offset.data[0] += camera_speed;
        }
        if (input.is_key_pressed(game::key::UP)) {
            cam_target_offset.data[2] -= camera_speed;
        }
        if (input.is_key_pressed(game::key::DOWN)) {
            cam_target_offset.data[2] += camera_speed;
        }

        auto &loc{spaceship.location()};
        auto &rot{spaceship.rotation()};
        if (input.is_key_pressed(game::key::A)) {
            spaceship.yaw(spaceship.yaw() + turn_speed * delta_time);
        }
        if (input.is_key_pressed(game::key::D)) {
            spaceship.yaw(spaceship.yaw() - (turn_speed * delta_time));
        }
        if (input.is_key_pressed(game::key::W)) {
            spaceship.acceleration(vec4{0.f, 0.f, acceleration * delta_time});
        }
        if (input.is_key_pressed(game::key::S)) {
            spaceship.acceleration(vec4{0.f, 0.f, -acceleration * delta_time});
        }
        if (input.is_key_pressed(game::key::Q)) {
            spaceship.roll(spaceship.roll() - turn_speed * delta_time);
        }
        if (input.is_key_pressed(game::key::E)) {
            spaceship.roll(spaceship.roll() + turn_speed * delta_time);
        }
        if (input.is_key_pressed(game::key::Z)) {
            spaceship.pitch(spaceship.pitch() - turn_speed * delta_time);
        }
        if (input.is_key_pressed(game::key::X)) {
            spaceship.pitch(spaceship.pitch() + turn_speed * delta_time);
        }
        if (input.is_key_pressed(game::key::M)) {
            cam_rotation_angle += camera_speed * delta_time;
        }
        if (input.is_key_pressed(game::key::N)) {
            cam_rotation_angle -= camera_speed * delta_time;
        }
        if (input.is_key_pressed(game::key::TAB)) {
            if (can_toggle_decouple) {
                spaceship.decoupled(!spaceship.decoupled());
                can_toggle_decouple = false;
            }
        } else {
            can_toggle_decouple = true;
        }
        if (input.is_key_pressed(game::key::SPACE)) {
            if (can_shoot) {
                can_shoot = false;
                projectiles.push_back(spaceship.shoot(p_id++));
                scene.renderables.push_back(&projectiles.back());
                projectiles.back().direction(spaceship_direction);
            }
        } else {
            can_shoot = true;
        }

        auto p = projectiles.begin();
        while (p != projectiles.end()) {
            if ((*p).expired()) {
                auto it = scene.renderables.begin();
                while (it != scene.renderables.end()) {
                    const auto p_proj = dynamic_cast<game::projectile *>((*it));
                    if (p_proj) {
                        if (p_proj->id() == (*p).id()) {
                            scene.renderables.erase(it);
                            break;
                        }
                    }
                    ++it;
                }
                p = projectiles.erase(p);
            } else {
                (*p).update(delta_time);
                if ((*p).check_collision(planet)) {
                    std::cout << "Game is technically won\n";
                }
                ++p;
            }
        }

        mat4 m1{1.f};
        mat4 m2{1.f};
        mat4 m3{1.f};
        float angle = (cam_rotation_angle * M_PI) / 180;
        m2.data[0][0] = cos(angle);
        m2.data[0][2] = sin(angle);
        m2.data[2][0] = -sin(angle);
        m2.data[2][2] = cos(angle);

        m1.data[0][3] = -spaceship.location().x();
        m1.data[1][3] = -spaceship.location().y();
        m1.data[2][3] = -spaceship.location().z();

        m3.data[0][3] = spaceship.location().x();
        m3.data[1][3] = spaceship.location().y();
        m3.data[2][3] = spaceship.location().z();

        auto r1 = m3 * m2 * m1;

        eye = eye.multiply(r1);
        auto camera = math::look_at(eye, lookat, {0, 1, 0});

        renderer.view(camera);
        renderer.render(scene);
        spaceship.rotation({i, 0, 0});
        i += 0.1f;
    }

    return 0;
}
