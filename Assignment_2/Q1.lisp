(defun split (list i) 
    (cond
        ((<= i 0) ())
        ((null list)(list))
        (t (cons (car list) (split (cdr list) (- i 1))))
    )
)

(defun sub-list (list fromIndex &optional (toIndex NIL))
    
  (cond
         ((equal toIndex NIL) (setf toIndex (list-length list)))
         ((or 
           (not (<= 1 fromIndex toIndex)) 
           (> toIndex (list-length list))) (return-from sub-list NIL))
  )
    (cond
         ((= 1 fromIndex) (split list toIndex))
         (t(sub-list (cdr list) (- fromIndex 1) (- toIndex 1)))
     )
   
)
;TESTING
(print (sub-list '(1 4 10) 2 3))
(print (sub-list '(1 4 10) 2 ))
(print (sub-list '(1 7 12) 1 4))
(print (sub-list '(1 7 12) 0 1))
(print (sub-list '(1 6 12) 4 2))
(print (sub-list '(1 6 12)))
