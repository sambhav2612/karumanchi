#!/usr/bin/env node

import program, {
    username,
    password
} from 'commander';
import chalk from 'chalk';

const [, , ...args] = process.argv;

console.log(`Sent arguments: ${args}`);

program
    .arguments('<file>')
    .option('-u, --username <username>', 'The user to authenticate as')
    .option('-p, --password <password>', 'The user\'s password')
    .action(function (file) {
        console.log(chalk.bold.cyan('user: %s pass: %s file: %s', username, password, file));
    })
    .parse(process.argv);
