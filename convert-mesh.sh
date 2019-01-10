#!/bin/sh

egrep 'v |f ' "$1" | sed -E 's/\/[0-9]+//g'
