#!/bin/bash
set -e
git pull
git submodule foreach git checkout master
git submodule foreach "git pull"
