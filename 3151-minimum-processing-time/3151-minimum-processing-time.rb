# @param {Integer[]} processor_time
# @param {Integer[]} tasks
# @return {Integer}
def min_processing_time(processor_time, tasks)
    n = tasks.length
    tasks.sort!
    processor_time.sort!.reverse!

    ans = -Float::INFINITY
    tasks_index = 3
    processor_time_index = 0

    while tasks_index < n
      ans = [ans, processor_time[processor_time_index] + tasks[tasks_index]].max
      tasks_index += 4
      processor_time_index += 1
    end
    ans
end
