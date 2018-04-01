#!/bin/bash
pwd
../../script/generate.pl -a -g applicationFor_tarray -m ../../src/ . for_tarray.in.c

## The only problem with this is that it leaves an application.c with ALL the calls in the src directory
(cd ../.. && script/generate.pl -a src)

