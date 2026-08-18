# Write your MySQL query statement below
select
round(
    sum(case when order_date = customer_pref_delivery_date then 1 else 0 end) * 100.0 / count(distinct customer_id), 2
) as immediate_percentage
from (
    select
    customer_id,
    order_date,
    customer_pref_delivery_date,
    row_number() over (partition by customer_id order by order_date asc) as rn from Delivery
) t where rn = 1;