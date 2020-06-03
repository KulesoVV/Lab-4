#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#pragma once

using namespace std;

template <class T>
class BinTree
{

public:
    T element;// число в дерево
    BinTree* left; // указатель на левого потомка
    BinTree* right; // указатель на правого потомка

    BinTree()
    {
        element = NULL;
        left = NULL;
        right = NULL;
    }
};


template <typename T>
BinTree<T>* Min(BinTree<T>* Tree, BinTree<T>*& prev) //Используется при удалении элемента
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

// удаление элемента
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
        else if (b < tree->element)  //   с помощью 1 и 2 if идем влево
            //потом вправо пока не найдем нужный элемент и не вызовем рекурсивную функцию
        {
            Delete(tree->left, b, tree); //рекурсия
        }
        else if (b > tree->element)
        {
            Delete(tree->right, b, tree); // рекурсия
        }
    }
    else
    {
        cout << " non element " << endl;
    }
}

// Проверка наличия элемента
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




// Добавить элемент к дереву
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

//Нарисовать дерево
template <typename T>
void print(BinTree<T>*& tree) {
    if (tree != NULL)
    {
        print(tree->left);//Переходим в левое поддерево пока не дойдем до конца слева
        cout << tree->element << endl; //Печатаем с левого конца поддерева
        print(tree->right);
    }
    else if (tree = NULL)
    {
        cout << "Tree is missing" << endl;
    }

}



//Удаление всех элементов дерева полностью
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
