
function swap(s: string, pos1: number, pos2: number): string {
  let arr = s.split('');
  [arr[pos1], arr[pos2]] = [arr[pos2], arr[pos1]];
  return arr.join('');
}

function canBeEqual(s1: string, s2: string): boolean {
  if (s1 === s2) {
    return true
  }
  s1 = swap(s1, 0, 2);
  if (s1 == s2) {
    return true
  }
  s1 = swap(s1, 1, 3);
  if (s1 == s2) {
    return true
  }
  s1 = swap(s1, 0, 2);
  if (s1 == s2) {
    return true
  }
  return false
};


console.log(canBeEqual("abcd", "cdab"))
