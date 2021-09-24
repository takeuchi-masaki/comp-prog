class MinStack {
    public static void main(String[] Args){
        MinStack obj = new MinStack();
        obj.push(5);
        System.out.println(obj.getMin());
        obj.push(2);
        System.out.println(obj.top());
        System.out.println(obj.getMin());
        obj.pop();
        System.out.println(obj.getMin());
        System.out.println(obj.top());
    }

    private Node top;
    private class Node{
        Node next;
        int val;
        int minVal;
        Node(int data){
            val = data;
            minVal = val;
            if(top==null){
                top = this;
            }
            minVal = Math.min(top.minVal, val);
            next = top;
            top = this;
        }
    }
    /** initialize your data structure here. */
    public MinStack() {

    }

    public void push(int x) {
        new Node(x);
    }

    public void pop() {
        top = top.next;
    }

    public int top() {
        return top.val;
    }

    public int getMin() {
        return top.minVal;
    }
}



/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */