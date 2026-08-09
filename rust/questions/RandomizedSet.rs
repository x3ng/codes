use rand::rngs::StdRng;
use rand::{Rng, SeedableRng};
use std::collections::HashMap;

struct RandomizedSet {
    v: Vec<i32>,
    hm: HashMap<i32, usize>,
    rng: StdRng,
}

impl RandomizedSet {
    fn new() -> Self {
        Self {
            v: Vec::new(),
            hm: HashMap::new(),
            rng: StdRng::from_entropy(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        if self.hm.contains_key(&val) {
            return false;
        }
        self.hm.insert(val, self.v.len());
        self.v.push(val);
        true
    }

    fn remove(&mut self, val: i32) -> bool {
        let Some(&idx) = self.hm.get(&val) else {
            return false;
        };
        let ev = *self.v.last().unwrap();
        self.v[idx] = ev;
        self.hm.insert(ev, idx);
        self.v.pop();
        self.hm.remove(&val);
        true
    }

    fn get_random(&mut self) -> i32 {
        let idx = self.rng.gen_range(0..self.v.len());
        self.v[idx]
    }
}
