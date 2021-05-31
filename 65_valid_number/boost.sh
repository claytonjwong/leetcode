#!/usr/bin/env bash
set -Eexo pipefail

bcp                                                  \
  algorithm/string/split.hpp                         \
  boost/algorithm/string/classification.hpp          \
  ./boost                                            \
  --boost=/usr/local/Cellar/boost/1.73.0/include
