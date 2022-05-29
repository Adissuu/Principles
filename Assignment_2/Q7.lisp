(defun left-tree (list)
    (if (null list) 
        list
        (car(cdr list))
    )
)
(defun right-tree (list)
    (if (null list) 
        list
        (car(cdr(cdr list)))
    )
)
(defun binary-tree(list)
    (and
        (if (car(left-tree list))
            (if(listp(left-tree list))
                (if(>=(car list) (car(left-tree list)))
                    (binary-tree (left-tree list))
                    nil
                )
                (if(left-tree list)
                    (>= (car list)(left-tree list))
                    T
                )
            )
            T
        )
        (if (car(right-tree list))
            (if(listp(right-tree list))
                (if(<(car list) (car(right-tree list)))
                    (binary-tree (right-tree list))
                    nil
                )
                (if(right-tree list)
                    (< (car list)(right-tree list))
                    T
                )
            )
            T
        )
        
    )
)
(print(binary-tree '(8 (3 (1 () ()) (6 (4 () ())(7 () ()))) (10 () (14 (13 () ()) ())))))