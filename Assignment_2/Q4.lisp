

(defun no-dup (list)
    (setf tempList list)
    (setf list (remove (car tempList) tempList))
    (setf li (list (car tempList) (car (cdr tempList))))
    (setf list (append li (remove (car list) list)))
    (setf list (remove NIL list))
)

(defun flatten-nums-nodup (list) 
        (no-dup (cond 
            ((null list)
                list)
            ((listp (car list))
                (append (flatten-nums-nodup (car list)) (flatten-nums-nodup (cdr list))))
            ((and (not (numberp (car list))) (not (listp (car list)))) 
                (flatten-nums-nodup (cdr list)))
            (t
                (cons (car list) (flatten-nums-nodup (cdr list)))
            ))))

(print (flatten-nums-nodup '(1 2 (3 1) (a 2.5) (2 4.5) ((1 2)))))
