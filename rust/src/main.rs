mod doubly_ll;
mod linked_list;

fn main() {
    /* Linked List */
    let mut l = linked_list::List::new(0);
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    println!("Len of list {}", l.len);
    let last_node_val = l.pop();
    println!("Last node val {}", last_node_val);
    l.print();

    /* Doubly Linked List */
    let mut _d_ll = doubly_ll::List::new(0);
}
