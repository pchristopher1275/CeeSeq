#!/bin/bash
find src/ -name '*.c' -o -name '*.h' | xargs grep "$@"
find script/ -name '*.pl' | xargs grep "$@"
