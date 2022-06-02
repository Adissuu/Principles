(defun depth (&optional list)
    (cond
        ((equal list NIL) (return-from depth 0))
        ((listp list) (+ 1 (reduce #'max (mapcar #'depth list))))
        (t (return-from depth 0))))

(print (depth '(2)))
(print (depth '((2))))
(print (depth '((2)(3 (6))(4))))
