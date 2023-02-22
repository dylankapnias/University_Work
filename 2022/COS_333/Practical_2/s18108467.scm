(define (coneVolume rad hei)
  (let
    (
      (pi (/ 22 7))
    )
    (cond
      ((negative? rad) 0)
      ((negative? hei) 0)
      (else (* pi (* rad rad) (/ hei 3)))
    )
  )
)

(display (coneVolume 3.2 1.8))
(newline)

(define (countNegatives lis)
  (cond
    ((null? lis) 0)
    ((negative? (car lis)) (+ 1 (countNegatives (cdr lis))))
    (else (+ 0 (countNegatives (cdr lis))))
  )
)

(display (countNegatives '(-1 20 -30 2 -5 40 10 -60)))
(newline)

(define (getEveryOddElement lis)
  (cond
    ((null? lis) '())
    ((null? (cdr lis)) (cons (car lis) '()))
    (else (cons (car lis) (getEveryOddElement (cdr (cdr lis)))))
  )
)

(display (getEveryOddElement '(a b c d e f)))
(newline)
