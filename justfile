lint:
  yarn eslint .

format:
  yarn prettier . --write
  clang-format -i ./src/*.c

build:
  clang -g ./src/main.c -o ./bin/main -lcs50

run:
  ./bin/main
  node ./src/app.js '[2, 3, 4, 5]'

test:
  NODE_OPTIONS=--experimental-vm-modules yarn jest

production: build format lint test
  pm2 start app.js --name app  

stop:
  pm2 stop nix-shell-env
  pm2 delete 0
  pm2 ls

clean:
  find ./bin -type f -name "*" -delete

c: build
  ./bin/main
