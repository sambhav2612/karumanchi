#! /usr/bin/env node

import { exec } from 'shelljs';

exec('git add -A . && git commit -a -m \'gh-pages update\'');
