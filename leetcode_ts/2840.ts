function checkStrings(s1: string, s2: string): boolean {
  const normalize = (s: string) => {
    const arr1: string[] = [];
    const arr2: string[] = [];
    for (let index = 0; index < s.length; index++) {
      if (index % 2 === 0) {
        arr1.push(s[index])
      } else {
        arr2.push(s[index])
      }
    }
    const g1 = arr1.sort().join('');
    const g2 = arr2.sort().join('');
    return g1 + '|' + g2;
  }
  return normalize(s1) === normalize(s2);
};
