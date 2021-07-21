Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
  
  
My Approach:
    Sort the intervals based on the starting point...
      Merge two intervals if...
        A[i].end >= A[i+1].start And so on..
