#!/usr/bin/env bash
set -Eeuxo pipefail

#
# 195. Tenth Line
# https://leetcode.com/problems/tenth-line/
#
sed -n '10p' < file.txt
