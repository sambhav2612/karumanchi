#! /usr/bin/env node

import { exec } from 'shelljs';

exec('git push origin master --force');
