(define (last lis)
    (cond
    ((null? lis) '())
    ((null? (cdr lis)) (cons (car lis) '()))
    (else (last (cdr lis)))
  )
)