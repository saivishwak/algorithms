#![allow(dead_code, unused_variables, unused_mut, unused_imports)]
use std::fmt::Debug;
use std::{cell::RefCell, rc::Rc};

struct Node<K> {
    value: K,
    next: Link<K>,
    prev: Link<K>,
}

pub struct List<T> {
    head: Link<T>,
    tail: Link<T>,
    len: i32,
}

type Link<T> = Option<Rc<RefCell<Node<T>>>>;

impl<T> List<T>
where
    T: Debug + Copy,
{
    pub fn new(value: T) -> Self {
        let node = Rc::new(RefCell::new(Node {
            value,
            next: None,
            prev: None,
        }));
        Self {
            head: Some(Rc::clone(&node)),
            tail: Some(node),
            len: 1,
        }
    }

    pub fn push_back(&mut self, value: T) {
        let node = Rc::new(RefCell::new(Node {
            value,
            next: None,
            prev: None,
        }));
        if let Some(tail) = self.tail.take() {
            tail.borrow_mut().next = Some(Rc::clone(&node));
            node.borrow_mut().prev = Some(tail);
            self.tail = Some(node);
            self.len += 1;
        } else {
            self.head = Some(Rc::clone(&node));
            self.tail = Some(node);
            self.len += 1;
        }
    }

    pub fn pop(&mut self) -> Option<T> {
        let mut ret_val = None;
        self.tail.take().map(|node| {
            ret_val = Some(node.borrow().value);
            let mut prev_node = node.borrow_mut();
            prev_node.next = None;
            self.len -= 1;
        });
        ret_val
    }
}

#[cfg(test)]
mod double_linked_list_test {
    use super::*;
    #[test]
    fn create() {
        let l = List::new(0);
        assert_eq!(l.len, 1);
    }

    #[test]
    fn push() {
        let mut l = List::new(0);
        l.push_back(1);
        assert_eq!(l.len, 2);
        let head = l.head.unwrap().borrow().value;
        assert_eq!(head, 0);
        let tail = l.tail.unwrap().borrow().value;
        assert_eq!(tail, 1);
    }

    #[test]
    fn pop() {
        let mut l = List::new(0);
        l.push_back(1);
        assert_eq!(l.len, 2);
        if let Some(n) = l.pop() {
            assert_eq!(n, 1);
        }
        assert_eq!(l.len, 1);

        if let Some(n) = l.head {
            assert_eq!(n.borrow().value, 0);
        }
    }
}
