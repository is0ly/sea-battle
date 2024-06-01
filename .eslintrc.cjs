module.exports = {
  env: {
    browser: true,
    es6: true,
    es2021: true,
  },
  extends: 'airbnb-base',
  plugins: ['json', 'promise', 'import', 'node', 'jest', 'optimize-regex'],
  overrides: [
    {
      env: {
        node: true,
      },
      files: ['.eslintrc.{js,cjs}'],
      parserOptions: {
        sourceType: 'script',
      },
    },
  ],
  parserOptions: {
    ecmaVersion: 'latest',
    sourceType: 'module',
  },
  rules: {
    'import/extensions': 'off',
  },
};
