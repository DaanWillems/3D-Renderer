#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

namespace bstd {

// trim from start (in place)
  static inline std::string &ltrim(std::string &s) {
    s.erase(0, s.find_first_not_of("\t\n\v\f\r "));
    return s;
  }

// trim from end (in place)
  static inline std::string &rtrim(std::string &s) {
    s.erase(s.find_last_not_of("\t\n\v\f\r ") + 1);
    return s;
  }

// trim from both ends (in place)
  static inline std::string &trim(std::string &s) {
    return rtrim(ltrim(s));
  }

  static inline std::string& to_lower(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
  }

  static inline std::string& to_upper(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
  }

// trim from start (copying)
  static inline std::string&& ltrim_copy(std::string s) {
    return std::move(ltrim(s));
  }

// trim from end (copying)
  static inline std::string&& rtrim_copy(std::string s) {
    return std::move(rtrim(s));
  }

// trim from both ends (in place)
  static inline std::string&& trim_copy(std::string s) {
    return std::move(trim(s));
  }

  static inline std::string to_lower_copy(std::string s) {
    to_lower(s);
    return s;
  }

  static inline std::string&& to_upper_copy(std::string s) {
    return std::move(to_upper(s));
  }

  template<typename Container, typename UnaryPredicate>
  auto remove_if(Container& container, UnaryPredicate p) {
    return std::remove_if(container.begin(), container.end(), p);
  }

  template<typename Container, typename UnaryPredicate>
  auto erase_if(Container& container, UnaryPredicate p) {
    return container.erase(remove_if(container, p), container.end());
  }

  template<typename Container, typename ForwardIter>
  auto erase(Container& container, ForwardIter begin) {
    return container.erase(begin, container.end());
  }

  template<typename Container, typename T>
  auto accumulate(Container& container, T init) {
    return std::accumulate(container.begin(), container.end(), init);
  }

  template<typename Container, typename T, typename BinaryOperation>
  auto accumulate(Container& container, T init, BinaryOperation op) {
    return std::accumulate(container.begin(), container.end(), init, op);
  }

  template<typename SourceContainer, typename OutputIt, typename UnaryOperation>
  auto transform(SourceContainer& source, OutputIt target, UnaryOperation op) {
    std::transform(source.begin(), source.end(), target, op);
  }

  template<typename Container, typename UnaryPredicate>
  auto find_if(Container& container, UnaryPredicate op) {
    return std::find_if(container.begin(), container.end(), op);
  }

  template<typename Container, typename UnaryPredicate>
  auto contains(Container& container, UnaryPredicate op) {
    return std::find_if(container.begin(), container.end(), op) != container.end();
  }

  template<typename Container, typename T>
  auto join(Container& container, T seperator) {
    return bstd::accumulate(container, std::string{}, [&seperator](const auto &prev, auto &curr) {
      return prev + (!prev.empty() ? seperator : "") + curr;
    });
  }

}
