
(defun split (list i) 
    (cond
        ((<= i 0) ())
        ((null list)(list))
        (t (cons (car list) (split (cdr list) (- i 1))))
    )
)

(defun sub-list2 (list fromIndex &optional (toIndex NIL))
    
     (if (equal toIndex NIL)
        (setf toIndex (list-length list)))

    (if (> fromIndex toIndex)
        (return-from sub-list2 NIL))
    
    (if (< fromIndex 1)
        (setf fromIndex 1))
    
    (if (> toIndex (list-length list))
        (setf toIndex (list-length list)))
   
    (cond
         ((= 1 fromIndex) (split list toIndex))
         (t(sub-list2 (cdr list) (- fromIndex 1) (- toIndex 1)))
     )
   
)

(print (sub-list2 '(1 4 10) 2 3))
(print (sub-list2 '(1 4 10) 2 ))
(print (sub-list2 '(1 7 12) 1 4))
(print (sub-list2 '(1 7 12) 0 1))
(print (sub-list2 '(1 6 12) 4 2))
(print (sub-list2 '(1 6 12)))