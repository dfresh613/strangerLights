#!/bin/bash

# Directory where this script is running in
export CURRDIR="$(cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

python slights-talkie-setup.py bdist_wheel
sudo pip uninstall  -y slightsTalkie
latest_package=`ls -t "$CURRDIR/dist/" | head -n 1`
sudo pip install "$CURRDIR/dist/$latest_package"

