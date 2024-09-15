void removeNodesWithEvenValues()
{
    Node* current = head1;
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (current->data % 2 == 0)
        {
            // Node with even value found, remove it
            if (current == head1)
            {
                head1 = current->next;  // Update head1 if removing the first node
            }
            else
            {
                prev->next = current->next;  // Link previous node to next node
            }

            Node* temp = current;
            current = current->next;
            delete temp;
        }
        else
        {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
}
