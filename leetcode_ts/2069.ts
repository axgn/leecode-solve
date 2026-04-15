class Robot2 {
  ss: string[];
  pos: number[];
  width: number;
  height: number;
  direction: number;
  constructor(width: number, height: number) {
    this.ss = ["North", "East", "South", "West"];
    this.width = width;
    this.height = height;
    this.direction = 1;
    this.pos = [0, 0];
  }

  check(): boolean {
    if (this.pos[0] >= this.width || this.pos[0] < 0) {
      return false;
    }
    if (this.pos[1] >= this.height || this.pos[1] < 0) {
      return false;
    }
    return true;
  }

  step(num: number): void {
    const funcs: (() => void)[] = [
      () => this.pos[1]++,
      () => this.pos[0]++,
      () => this.pos[1]--,
      () => this.pos[0]--,
    ];
    while (num > 0) {
      funcs[this.direction]();
      while (!this.check()) {
        funcs[(this.direction + 2) % 4]();
        this.direction = (this.direction + 3) % 4;
        funcs[this.direction]();
      }
      num -= 1;
    }
  }

  getPos(): number[] {
    return this.pos;
  }

  getDir(): string {
    return this.ss[this.direction];
  }
}

class Robot {
  private moved: boolean = false;
  private idx: number = 0;
  private pos: number[][] = [];
  private dir: number[] = [];
  private toDir: Map<number, string> = new Map();

  constructor(width: number, height: number) {
    this.toDir.set(0, "East");
    this.toDir.set(1, "North");
    this.toDir.set(2, "West");
    this.toDir.set(3, "South");

    for (let i = 0; i < width; ++i) {
      this.pos.push([i, 0]);
      this.dir.push(0);
    }
    for (let i = 1; i < height; ++i) {
      this.pos.push([width - 1, i]);
      this.dir.push(1);
    }
    for (let i = width - 2; i >= 0; --i) {
      this.pos.push([i, height - 1]);
      this.dir.push(2);
    }
    for (let i = height - 2; i > 0; --i) {
      this.pos.push([0, i]);
      this.dir.push(3);
    }
    this.dir[0] = 3;
  }

  step(num: number): void {
    this.moved = true;
    this.idx = (this.idx + num) % this.pos.length;
  }

  getPos(): number[] {
    return this.pos[this.idx];
  }

  getDir(): string {
    if (!this.moved) {
      return "East";
    }
    return this.toDir.get(this.dir[this.idx])!;
  }
}

const r = new Robot2(6, 3);
r.step(2);
r.step(2);
r.step(2);
r.step(1);
r.step(4);
console.log(r.getPos());
console.log(r.getDir());
