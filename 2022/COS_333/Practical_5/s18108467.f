      program s18108467
        implicit none
        integer, dimension(1:5) :: inputArray
        real :: k = 0

        call readData(inputArray)
        print *, stdDev(inputArray)

      contains
        function stdDev(inArr) result(dev)
          implicit none
          integer :: i = 0
          integer, dimension(1:5) :: inArr
          real :: mean
          real :: dev

          mean = sum(inArr)/size(inArr)

          do i = 1, 5
            inArr(i) = inArr(i) - mean
            inArr(i) = inArr(i) ** 2
          end do

          dev = sum(inArr) / size(inArr)
          dev = sqrt(dev)
        end function stdDev

        subroutine readData(outArr)
          implicit none
          integer, dimension(1:5) :: outArr
          integer :: i = 0

          do i = 1, 5
            print *, "Please insert a number"
            read *, outArr(i)
          end do
        end subroutine readData

      end program s18108467
