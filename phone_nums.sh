#!/usr/bin/env bash
set -Eeuxo pipefail

#
# 193. Valid Phone Numbers
# https://leetcode.com/problems/valid-phone-numbers/
#
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

