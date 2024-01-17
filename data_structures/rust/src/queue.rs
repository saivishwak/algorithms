#![allow(dead_code, unused_variables, unused_mut, unused_imports)]
use super::stack::Stack;
use std::vec::Vec;

pub struct Queue<T> {
    s1: Stack<T>,
    s2: Stack<T>,
}

impl<T> Queue<T>
where
    T: Copy,
{
    pub fn new() -> Self {
        Self {
            s1: Stack::<T>::new(),
            s2: Stack::<T>::new(),
        }
    }

    pub fn get_size(&self) -> usize {
        self.s1.get_len()
    }

    pub fn enqueue(&mut self, value: T) {
        if self.s1.get_len() > 0 {
            while let Some(n) = self.s1.pop() {
                self.s2.push(n);
            }
        }
        self.s1.push(value);

        if self.s2.get_len() > 0 {
            while let Some(n) = self.s2.pop() {
                self.s1.push(n);
            }
        }
    }

    pub fn dequeue(&mut self) -> Option<T> {
        self.s1.pop()
    }

    // Return the front of the queue
    pub fn peek(&self) -> Option<T> {
        self.s1.get_top()
    }
}

#[cfg(test)]
mod queue_test {
    use super::*;
    #[test]
    fn create() {
        let mut queue = Queue::<i32>::new();
        queue.enqueue(0);
        assert_eq!(queue.get_size(), 1);
    }

    #[test]
    fn push() {
        let mut queue = Queue::<i32>::new();
        queue.enqueue(0);
        queue.enqueue(1);
        assert_eq!(queue.get_size(), 2);
        if let Some(top) = queue.peek() {
            assert_eq!(top, 0);
        }
    }

    #[test]
    fn pop() {
        let mut queue = Queue::<i32>::new();
        queue.enqueue(0);
        queue.enqueue(1);
        assert_eq!(queue.get_size(), 2);
        assert_eq!(queue.dequeue().unwrap(), 0);
        assert_eq!(queue.dequeue().unwrap(), 1);
        assert_eq!(queue.get_size(), 0);
    }

    #[test]
    fn peek() {
        let mut queue = Queue::<i32>::new();
        queue.enqueue(0);
        assert_eq!(queue.peek().unwrap(), 0);
    }
}
