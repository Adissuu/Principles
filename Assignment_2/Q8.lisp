(defun pre-order (list)
    (cond
        ((null list) nil)
        ((null (cdr list)) (list (car list)))
        ((append
            (list(car list)) ; root of tree - do first
            (pre-order(car(cdr list))) ; left part of tree
            (pre-order(car(cdr(cdr list)))) ; right part
        ))
    )
)

(defun in-order (list)
    (cond 
        ((null list) nil)
        ((null (cdr list)) (list (car list)))
        ((append 
            (in-order (car (cdr list))) ; left part - do first 
            (list (car list)); root
            (in-order (car (cdr (cdr list)))) ;right part
        ))
    )
)

(print (in-order '(+ (- (1 () ()) (* (4 () ())(7 () ()))) (/ (7 () ()) (6 () ())))))
(print (pre-order '(+ (- (1 () ()) (* (4 () ())(7 () ()))) (/ (7 () ()) (6 () ())))))