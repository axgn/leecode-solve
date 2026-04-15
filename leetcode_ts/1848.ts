function getMinDistance(nums: number[], target: number, start: number): number {
  let min: number = Number.MAX_VALUE;
  for (let index = 0; index < nums.length; index++) {
    const element = nums[index];
    if (target === element) {
      let temp: number = Math.abs(index - start);
      if (temp < min) {
        min = temp;
      }
    }
  }
  return min;
}
