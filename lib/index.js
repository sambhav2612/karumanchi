#!/usr/bin/env node
"use strict";

function _toArray(arr) { return Array.isArray(arr) ? arr : Array.from(arr); }

var _process$argv = _toArray(process.argv),
    args = _process$argv.slice(2);

console.log("Sent arguments - " + args);