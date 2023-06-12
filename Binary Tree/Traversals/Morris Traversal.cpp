// Inorder traversal
void MorrisTraversal(node* root)
{
    node *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}

// Preorder
void morrisTraversalPreorder(node* root)
{	node* curr = root;
	while (curr)
	{
		// If left child is null, print the current node data. Move to
		// right child.
		if (curr->left == NULL)
		{
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else
		{
			// Find inorder predecessor
          
			node* pred = curr->left;
			while (pred->right && pred->right != curr)
				pred = pred->right;

			// If the right child of inorder predecessor already points to
			// this node
			if (pred->right == curr)
			{
				pred->right = NULL;
				curr = curr->right;
			}

			// If right child doesn't point to this node, then print this
			// node and make right child point to this node
			else
			{
				cout<<curr->data<<" ";
				pred->right = curr;
				curr = curr->left;
			}
		}
	}
}
