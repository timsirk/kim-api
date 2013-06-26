!-------------------------------------------------------------------------------
!
! setup_neighborlist_Rij_KIM_access :
!
!    Store necessary pointers in KIM API object to access the neighbor list
!    data and methods.
!
!-------------------------------------------------------------------------------
subroutine setup_neighborlist_Rij_KIM_access(pkim, NLRvecLocs)
  use KIM_API
  implicit none

  !-- Transferred variables
  integer(kind=kim_intptr), intent(in)    :: pkim
  integer(kind=kim_intptr), intent(inout) :: NLRvecLocs(3)

  !-- Local variables
  integer(kind=kim_intptr), parameter :: SizeOne = 1
  integer,                  external  :: get_neigh_Rij
  integer ier, idum

  ! store pointers to neighbor list object and access function
  !
  ier = kim_api_set_data_f(pkim, "neighObject", SizeOne, loc(NLRvecLocs))
  if (ier.lt.KIM_STATUS_OK) then
     idum = kim_api_report_error_f(__LINE__, THIS_FILE_NAME, &
                                   "kim_api_set_data_f", ier)
     stop
  endif
  ier = kim_api_set_method_data_f(pkim, "get_neigh", SizeOne,&
       loc(get_neigh_Rij))
  if (ier.lt.KIM_STATUS_OK) then
     idum = kim_api_report_error_f(__LINE__, THIS_FILE_NAME, &
                                   "kim_api_set_method_data_f", ier)
     stop
  endif

  return

end subroutine setup_neighborlist_Rij_KIM_access
