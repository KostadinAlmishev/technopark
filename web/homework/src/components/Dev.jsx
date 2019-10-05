import React, { Component } from 'react';
import {
    Input,
    Avatar,
    Menu,
    Tag,
    Divider,
    Pagination,
    Layout,
} from 'antd';

import QuestionCard from './QuestionCard';
import styles from './Dev.module.scss';
import Header from 'antd/lib/calendar/Header';

export default class Dev extends Component {

    constructor() {
        super()

        this.tmp = this.tmp.bind(this);
    }
    
    tmp() {

    }
    render() {
        return (
            <div className={ styles.wrapper} >
                <div className={ styles.header }>
                    <Menu
                        inlineIndent
                        className={ styles.menu }
                        mode='horizontal'
                    >
                        <Menu.Item>
                            kek
                        </Menu.Item>
                    </Menu>
                    <Input.Search
                        className={ styles.search }
                        placeholder='Inter search text'
                        onSearce={ value => console.log(value) }
                    />
                </div>
                <div className={ styles.content }>
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <QuestionCard />
                    <Pagination className={ styles.pagination } defaultCurrent={1} total={500} />
                </div>
                <div className={ styles.sider }>
                    <div className={ styles.popularTags }>
                        <Divider orientation='left'>Popular Tags</Divider>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>perl</Tag>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>python</Tag>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>TechnoPark</Tag>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>MySQL</Tag>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>django</Tag>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>Mail.Ru</Tag>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>Voloshin</Tag>
                        <Tag className={ styles.tag } closable onClose={ this.tmp }>Firefox</Tag>
                    </div>
                    <div className={ styles.bestMembers }>
                        <Divider orientation='left'>Best Members</Divider>
                        <div>
                            <Avatar src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />
                            <a hrif="#">Mr. Freeman</a>
                        </div>
                        <div>
                            <Avatar src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />
                            <a hrif="#">Dr. House</a>
                        </div>
                        <div>
                            <Avatar src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />
                            <a hrif="#">Bender</a>
                        </div>
                        <div>
                            <Avatar src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />
                            <a hrif="#">Queen Victoria</a>
                        </div>
                        <div>
                            <Avatar src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />
                            <a hrif="#">V. Pupkin</a>
                        </div>
                    </div>
                </div>
            </div>
        )
    }
}
