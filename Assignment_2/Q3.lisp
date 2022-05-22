(defun reversing (list)
    (cond 
        ((null list) '())
        (t (append (reversing (cdr list)) (list (car list))))))

(defun split (list i) 
    (cond
        ((<= i 0) ())
        ((null list)(list))
        (t (cons (car list) (split (cdr list) (- i 1))))
    )
)

(defun sub-list3 (list fromIndex &optional (toIndex NIL))
    
     (if (equal toIndex NIL)
        (setf toIndex (list-length list)))
    
    (if (> fromIndex toIndex)
        (progn
            (setf tToIndex toIndex)
            (setf toIndex fromIndex)
            (setf fromIndex tToIndex)))

    (if (> fromIndex toIndex)
        (return-from sub-list3 NIL))
    
    (if (< fromIndex 1)
        (setf fromIndex 1))
    
    (if (> toIndex (list-length list))
        (setf toIndex (list-length list)))
   
    (cond
         ((= 1 fromIndex) (reversing(split list toIndex)))
         (t(sub-list3 (cdr list) (- fromIndex 1) (- toIndex 1)))
     )
   
)

(print (sub-list3 '(1 4 10) 3 2))
(print (sub-list3 '(1 4 10) 3 ))
(print (sub-list3 '(1 7 12) 4 0))
(print (sub-list3 '(1 7 12) 0 1))
(print (sub-list3 '(1 6 12) 4 2))
