(defun reverseList (list)
    (cond 
        ((null list) '())
        (t (append (reverseList (cdr list)) (list (car list))))))

(defun reverseList (list)
    (cond 
        ((null list) '())
        (t (append (reverseList (cdr list)) (list (car list))))))

(defun tribonacci-seqInc (number)
    (setq zero 0)
    (setq zero2 0)
    (setq one 1)
        (let (list) 
             (dotimes (count number list)
                 (setf list (cons zero list))
                 (setf temp (+ zero zero2 one))
                 (setf zero zero2)
                 (setf zero2 one)
                 (setf one temp))
             (reverseList list)))

(print (tribonacci-seqInc 10))

(defun tribonacci-seqRec (n &optional (x 0) (y 0) (z 1) (list ()))
    (if (equal n 0)
        (reverseList list)
        (tribonacci-seqRec (1- n) y z (+ x y z) (cons x list))))

(print (tribonacci-seqRec 10))