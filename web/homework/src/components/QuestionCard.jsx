import React, { Component } from 'react'

import {
    Card,
    Button,
    Avatar,
    Tag,
} from 'antd';


import styles from './QuestionCard.module.scss'

export default class QuestionCard extends Component {
    render() {
        return (
            <Card
                className={ styles.card }
                size='small'
                title='How to build a moon park?'
                extra={
                    <a href='#'>More</a>
                }
            > 
                <Card.Meta
                    title='Ruslan Melnikoff'
                    description='Bauman Moscow State Technikal University'
                    avatar={<Avatar src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />}
                />
                <div className={ styles.cardContent}>
                    Guys, i have trouble with a moon park.
                    Can't find th black-jack...
                </div>
                <div className={ styles.cardLastLine }>
                    <Button.Group>
                        <Button type='primary' icon='dislike'>Dislike</Button>
                        <Button type='danger' icon='like'>Like</Button>
                    </Button.Group>
                    <span className={ styles.comments }>
                        <a href='#'>Comment (3)</a>
                    </span>
                    <span>
                        Tags: 
                        <Tag className={ styles.tag }>Python</Tag>
                        <Tag className={ styles.tag }>Django</Tag>
                    </span>
                </div>

            </Card>
        )
    }
}
