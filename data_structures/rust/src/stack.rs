#![allow(dead_code, unused_variables, unused_mut, unused_imports)]

use std::vec::Vec;

pub struct Stack<T> {
    data: Vec<T>,
}

impl<T> Stack<T>
where
    T: Copy,
{
    pub fn new() -> Self {
        Self { data: Vec::new() }
    }

    pub fn get_len(&self) -> usize {
        self.data.len()
    }

    pub fn push(&mut self, value: T) {
        self.data.push(value);
    }

    pub fn pop(&mut self) -> Option<T> {
        self.data.pop()
    }

    pub fn get_top(&self) -> Option<T> {
        if self.data.len() > 0 {
            return Some(self.data[self.get_len() - 1]);
        }
        None
    }
}

#[cfg(test)]
mod stack_test {
    use super::*;
    #[test]
    fn create() {
        let mut stack = Stack::<i32>::new();
        stack.push(0);
        assert_eq!(stack.get_len(), 1);
    }

    #[test]
    fn pop() {
        let mut stack = Stack::<i32>::new();
        stack.push(0);
        stack.push(1);
        assert_eq!(stack.get_len(), 2);
        let val = stack.pop().unwrap();
        assert_eq!(val, 1);
        assert_eq!(stack.get_len(), 1);
    }

    #[test]
    fn top() {
        let mut stack = Stack::new();
        stack.push(0);
        stack.push(1);
        assert_eq!(stack.get_top().unwrap(), 1);
    }
}
