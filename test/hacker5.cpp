/*
 * Complete the 'reversePrint' function below.
 *
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void reversePrint(SinglyLinkedListNode* llist) {
    int loops=1;
    int size = llist->data;
    SinglyLinkedListNode* current = llist;
    current = current->next;
    while (size>=loops){
        int length = current->data;
        int x = length;
        SinglyLinkedListNode* place = current;
        SinglyLinkedList* line = new SinglyLinkedList();
        for (int i=0; i<x; i++){
            for (int j=x-i; j>0; j--){
                place = place->next;  
            }
            line->insert_node(place->data);
            place = current;
        }
        print_singly_linked_list(line, "\n");
        free_singly_linked_list(line);
        for(int i=0; i<=x; i++){
            current = current->next;
        }
        loops = loops+1;
    }
}