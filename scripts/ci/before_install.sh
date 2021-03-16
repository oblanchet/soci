#!/bin/bash
# Run before_install actions for SOCI build at travis-ci.org
#
# Copyright (c) 2013 Mateusz Loskot <mateusz@loskot.net>
#
source ${SOCI_SOURCE_DIR}/scripts/ci/common.sh

sudo apt-get update -qq -y
sudo apt-get install -qq -y libc6-dbg libboost-dev libboost-date-time-dev

before_install="${SOCI_SOURCE_DIR}/scripts/ci/before_install_${SOCI_TRAVIS_BACKEND}.sh"
if [ -x ${before_install} ]; then
    echo "Running ${before_install}"
    ${before_install}
fi
