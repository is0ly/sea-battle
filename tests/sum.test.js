import sum from '../src/modules/sum';

test('sum of array [2, 2, 2] to equal 6', () => {
  expect(sum([2, 2, 2])).toBe(6);
});
