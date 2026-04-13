function xorAfterQueries(nums: number[], queries: number[][]): number {
  const MOD = 1e9 + 7;
  for (const element of queries) {
    let [l, r, k, v] = element;
    for (let index = l; index <= r; index += k) {
      nums[index] = Number((BigInt(nums[index]) * BigInt(v)) % BigInt(MOD));
    }
  }
  let res: number = 0;
  // nums.forEach((element) => {
  //   res ^= element;
  // });
  for (const element of nums) {
    res ^= element;
  }
  return res;
}
