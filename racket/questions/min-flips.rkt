(define/contract (min-flips s)
  (-> string? exact-integer?)
  (let* ([ss (string-length s)]
         [pattern #("0" "1")])
    (let loop ([p 0]
               [cnt 0]
               [ans ss])
      (if (>= p (- (* ss 2) 1))
          ans
          (let* ([cp (modulo p ss)]
                 [pp (modulo p 2)]
                 [match? (string=? (string (string-ref s cp)) (vector-ref pattern pp))]
                 [ncnt (+ cnt (if match? 1 0))]
                 [lb (- p (- ss 1))])
            (if (< lb 0)
                (loop (add1 p) ncnt ans)
                (let* ([flip0 (- ss ncnt)]
                       [flip1 ncnt]
                       [nans (min ans (min flip0 flip1))]
                       [lbpp (modulo lb 2)]
                       [lc (string (string-ref s lb))]
                       [lmatch? (string=? lc (vector-ref pattern lbpp))]
                       [ncntd (- ncnt (if lmatch? 1 0))])
                  (loop (add1 p) ncntd nans))))))))
