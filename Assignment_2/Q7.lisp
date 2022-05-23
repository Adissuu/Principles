(defun leftChild (list)
    (if (null list) 
        list
        (car(cdr list))
    )
)
(defun rightChild (list)
    (if (null list) 
        list
        (car(cdr(cdr list)))
    )
)
(defun isBinarySearchTree(list)
    (and
        (if (car(leftChild list))
            (if(listp(leftChild list))
                (if(>=(car list) (car(leftChild list)))
                    (isBinarySearchTree (leftChild list))
                    nil
                )
                (if(leftChild list)
                    (>= (car list)(leftChild list))
                    T
                )
            )
            T
        )
        (if (car(rightChild list))
            (if(listp(rightChild list))
                (if(<(car list) (car(rightChild list)))
                    (isBinarySearchTree (rightChild list))
                    nil
                )
                (if(rightChild list)
                    (< (car list)(rightChild list))
                    T
                )
            )
            T
        )
        
    )
)
(print(isBinarySearchTree '(8 (3 (1 () ()) (6 (4 () ())(7 () ()))) (10 () (14 (13 () ()) ())))))