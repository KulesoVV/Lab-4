#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#pragma once

using namespace std;

template <class T>
class BinTree
{

public:
    T element;// ����� � ������
    BinTree* left; // ��������� �� ������ �������
    BinTree* right; // ��������� �� ������� �������

    BinTree()
    {
        element = NULL;
        left = NULL;
        right = NULL;
    }
};


template <typename T>
BinTree<T>* Min(BinTree<T>* Tree, BinTree<T>*& prev) //������������ ��� �������� ��������
{

    if (Tree == NULL)
    {
        return NULL;
    }
    if (Tree->left != NULL)
    {
        BinTree<T>* tmp = Min(Tree->left, Tree);
        prev = Tree;
        return tmp;
    }
    else
    {
        return Tree;
    }
}

// �������� ��������
template <typename T>
void Delete(BinTree<T>* tree, T b, BinTree<T>* prev = NULL)
{
    if (tree != NULL)
    {
        if (b == tree->element)
        {
            if ((tree->left == NULL) && (tree->right == NULL))
            {
                if (prev != NULL && prev->element <= tree->element)
                    prev->right = NULL;
                else
                    prev->left = NULL;
                delete tree;
            }
            else if (tree->left == NULL && tree->right != NULL)
            {
                if (prev != NULL && prev->element <= tree->element)
                    prev->right = tree->right;
                else
                    prev->left = tree->right;
                delete tree;
            }
            else if (tree->left != NULL && tree->right == NULL) {
                if (prev != NULL && prev->element <= tree->element)
                    prev->right = tree->left;
                else
                    prev->left = tree->left;
                delete tree;

            }
            else if (tree->left != NULL && tree->right != NULL)
            {
                BinTree<T>* prev = NULL;
                BinTree<T>* ptr = Min(tree->right, prev);
                if (ptr->right == NULL) {
                    if (prev != NULL)
                        prev->left = NULL;
                }
                else {
                    if (prev != NULL)
                        prev->left = ptr->right;
                }
                tree->element = ptr->element;
                delete ptr;
            }

        }
        else if (b < tree->element)  //   � ������� 1 � 2 if ���� �����
            //����� ������ ���� �� ������ ������ ������� � �� ������� ����������� �������
        {
            Delete(tree->left, b, tree); //��������
        }
        else if (b > tree->element)
        {
            Delete(tree->right, b, tree); // ��������
        }
    }
    else
    {
        cout << " non element " << endl;
    }
}

// �������� ������� ��������
template <typename T>
void isContains(BinTree<T>* Tree, T a)
{
    if (Tree != NULL)
    {
        if (Tree->element == a)
        {
            cout << "Item found..." << endl;
            return;
        }
        else if (a < Tree->element)
        {
            isContains(Tree->left, a);
        }
        else if (a > Tree->element)
        {
            isContains(Tree->right, a);
        }

    }
    else
    {
        cout << "Item is missing!" << endl;
    }
}




// �������� ������� � ������
template <typename T>
void Insert(BinTree<T>*& TREE, T k)
{
    if (TREE == NULL)
    {
        TREE = new BinTree<T>;
        TREE->element = k;
        TREE->left = TREE->right = NULL;
    }


    if (k < TREE->element)
    {
        if (TREE->left != NULL)
        {
            Insert(TREE->left, k);
        }
        else
        {
            TREE->left = new BinTree<T>;
            TREE->left->left = TREE->left->right = NULL;
            TREE->left->element = k;
        }

    }


    if (k > TREE->element)
    {
        if (TREE->right != NULL)
        {
            Insert(TREE->right, k);
        }
        else
        {
            TREE->right = new BinTree<T>;
            TREE->right->right = TREE->right->left = NULL;
            TREE->right->element = k;
        }
    }
}

//���������� ������
template <typename T>
void print(BinTree<T>*& tree) {
    if (tree != NULL)
    {
        print(tree->left);//��������� � ����� ��������� ���� �� ������ �� ����� �����
        cout << tree->element << endl; //�������� � ������ ����� ���������
        print(tree->right);
    }
    else if (tree = NULL)
    {
        cout << "Tree is missing" << endl;
    }

}



//�������� ���� ��������� ������ ���������
template <typename T>
void Clear(BinTree<T>* tree)
{
    if (tree != NULL)
    {
        Clear(tree->left);
        Clear(tree->right);
        delete tree;
        tree = NULL;
    }
}



#endif // TREE_H_INCLUDED
