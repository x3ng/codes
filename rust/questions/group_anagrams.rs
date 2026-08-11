use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut hm: HashMap<Vec<u8>, Vec<String>> = HashMap::new();
        for s in strs {
            let mut sv = s.as_bytes().to_vec();
            sv.sort_unstable();
            hm.entry(sv).or_default().push(s);
        }
        hm.into_values().collect()
    }
}
