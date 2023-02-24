#![allow(dead_code, unused_variables, unused_mut)]
struct Node<K> {
    value: K,
    next: Option<Box<Node<K>>>,
    prev: Option<Box<Node<K>>>,
}

pub struct List<T> {
    head: Box<Node<T>>,
}

impl<T> List<T> {
    pub fn new(value: T) -> Self {
        Self {
            head: Box::new(Node {
                value,
                next: None,
                prev: None,
            }),
        }
    }

    pub fn push(&mut self, value: i32) {
        let mut curr = &mut self.head;
    }
}
