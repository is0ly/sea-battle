import sum from './modules/sum.js';

const argString = process.argv[2];

const argsArray = JSON.parse(argString);

console.log(sum(argsArray));
