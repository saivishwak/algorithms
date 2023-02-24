struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

pub struct List {
    head: Box<Node>,
    pub len: i32,
}

impl List {
    pub fn new(value: i32) -> Self {
        Self {
            head: Box::new(Node { value, next: None }),
            len: 1,
        }
    }

    pub fn print(&mut self) {
        let mut curr = &mut self.head;
        println!("{}", curr.value);
        while let Some(ref mut node) = curr.next {
            println!("{}", node.value);
            curr = node;
        }
    }

    pub fn push(&mut self, val: i32) {
        let mut curr = &mut self.head;
        while let Some(ref mut n) = curr.next {
            curr = n;
        }
        let new_node = Box::new(Node {
            value: val,
            next: None,
        });
        curr.next = Some(new_node);
        self.len += 1;
    }

    pub fn pop(&mut self) -> i32 {
        let mut curr = &mut self.head;
        let mut i = self.len;
        let mut ret_val = -1;
        if i == 2 {
            if let Some(ref val) = curr.next {
                ret_val = val.value;
            } else {
                return -1;
            }

            self.len -= 1;
            curr.next = None;
            return ret_val;
        }
        while let Some(ref mut n) = curr.next {
            i -= 1;
            if i <= 2 {
                if let Some(ref val) = n.next {
                    ret_val = val.value;
                } else {
                    return -1;
                }

                self.len -= 1;
                n.next = None;
                break;
            }
            curr = n;
        }

        ret_val
    }
}

#[cfg(test)]
mod linked_list_test {
    use super::*;
    #[test]
    fn create() {
        let l = List::new(0);
        assert_eq!(l.len, 1);
        assert_eq!(l.head.value, 0);
    }

    #[test]
    fn push() {
        let mut l = List::new(0);
        l.push(1);
        assert_eq!(l.len, 2);
        assert_eq!(l.head.next.unwrap().value, 1);
    }

    #[test]
    fn pop() {
        let mut l = List::new(0);
        l.push(1);
        assert_eq!(l.len, 2);
        let mut val = -1;
        if let Some(ref n) = l.head.next {
            val = n.value;
        }
        assert_eq!(val, 1);
        let last = l.pop();
        assert_eq!(l.len, 1);
        assert_eq!(last, 1);
    }

    #[test]
    fn multiple_push_pop() {
        let mut l = List::new(0);
        for i in 0..4 {
            l.push(i);
        }
        assert_eq!(l.len, 5);

        for _ in 0..2 {
            l.pop();
        }
        assert_eq!(l.len, 3);
    }
}
