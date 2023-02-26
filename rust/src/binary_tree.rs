#![allow(dead_code, unused_variables, unused_mut, unused_imports)]
use super::queue::Queue;
use std::fmt::Debug;
use std::{cell::RefCell, rc::Rc};

pub struct Node<T> {
    value: T,
    left: Link<T>,
    right: Link<T>,
}

type Link<T> = Option<Rc<RefCell<Node<T>>>>;

pub struct Tree<T> {
    root: Link<T>,
    size: i32,
}

impl<T> Tree<T>
where
    T: Copy + Debug,
{
    pub fn new(value: T) -> Self {
        Self {
            root: Some(Rc::new(RefCell::new(Node {
                value,
                left: None,
                right: None,
            }))),
            size: 1,
        }
    }

    pub fn get_size(&self) -> i32 {
        self.size
    }

    // Insert into a complete binary tree
    pub fn add_node(&mut self, value: T) {
        if let Some(ref mut node) = self.root {
            let n = node.clone();
            let mut queue = vec![n];
            let mut index = 0;
            loop {
                let queue_clone = queue[index].clone();
                let mut queue_borrow = queue_clone.borrow_mut();
                if let Some(ref n) = queue_borrow.left {
                    queue.push(n.clone());
                } else {
                    println!("Adding {:?} to left", value);
                    queue_borrow.left = Some(Rc::new(RefCell::new(Node {
                        value,
                        left: None,
                        right: None,
                    })));
                    self.size += 1;
                    return;
                }

                if let Some(ref n) = queue_borrow.right {
                    queue.push(n.clone());
                } else {
                    println!("Adding {:?} to right", value);
                    queue_borrow.right = Some(Rc::new(RefCell::new(Node {
                        value,
                        left: None,
                        right: None,
                    })));
                    self.size += 1;
                    return;
                }
                index += 1;
            }
        }
    }

    pub fn in_order(&self, node: &Link<T>) {
        if let Some(n) = node {
            let n = n.clone();
            let s = n.borrow();
            self.in_order(&s.left);
            println!("{:?} - ", s.value);
            self.in_order(&s.right);
        }
    }

    pub fn pre_order(&self, node: &Link<T>) {
        if let Some(n) = node {
            let n = n.clone();
            let s = n.borrow();
            println!("{:?} - ", s.value);
            self.pre_order(&s.left);
            self.pre_order(&s.right);
        }
    }

    pub fn post_order(&self, node: &Link<T>) {
        if let Some(n) = node {
            let n = n.clone();
            let s = n.borrow();
            self.post_order(&s.left);
            self.post_order(&s.right);
            println!("{:?} - ", s.value);
        }
    }
}

#[cfg(test)]
mod tree_test {
    use super::*;
    #[test]
    fn create() {
        let mut tree = Tree::<i32>::new(0);
        tree.add_node(1);
        tree.add_node(2);
        tree.add_node(3);

        println!("In Order");
        tree.in_order(&tree.root);

        println!("Pre order");
        tree.pre_order(&tree.root);

        println!("Post order");
        tree.post_order(&tree.root);

        assert_eq!(tree.get_size(), 4);
    }
}
